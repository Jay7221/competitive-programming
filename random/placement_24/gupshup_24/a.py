class PrimitiveHashMap:
    def __init__(self):
        self.byte_array = None
        self.page_size = 0
        self.num_pages = 0

    def init(self, page_size, num_pages):
        # Calculate the total size of the byte array
        total_size = 18 + (page_size * num_pages)
        self.byte_array = bytearray(total_size)
        
        # Store the page size and number of pages
        self.page_size = page_size
        self.num_pages = num_pages
        
        # Store the page size (bytes 0-3)
        self.byte_array[0:4] = page_size.to_bytes(4, 'big')
        # Store the number of pages (bytes 4-7)
        self.byte_array[4:8] = num_pages.to_bytes(4, 'big')
        
        # Initialize special keys (-1 and 0)
        self.byte_array[8] = 0  # -1 flag
        self.byte_array[9:13] = (0).to_bytes(4, 'big')  # -1 value
        self.byte_array[13] = 0  # 0 flag
        self.byte_array[14:18] = (0).to_bytes(4, 'big')  # 0 value
    
    def put(self, key, value):
        if key == -1:
            # Update for key -1
            self.byte_array[8] = 1  # Set the flag to 1
            self.byte_array[9:13] = value.to_bytes(4, 'big')  # Store the value
        elif key == 0:
            # Update for key 0
            self.byte_array[13] = 1  # Set the flag to 1
            self.byte_array[14:18] = value.to_bytes(4, 'big')  # Store the value
        else:
            # General case: find the page and insert/update the value
            page_index = key % self.num_pages
            page_start = 18 + (self.page_size * page_index)
            
            for i in range(0, self.page_size, 8):
                key_bytes = self.byte_array[page_start + i:page_start + i + 4]
                stored_key = int.from_bytes(key_bytes, 'big')
                if stored_key in [0, -1]:
                    # Empty slot found, insert the key and value
                    self.byte_array[page_start + i:page_start + i + 4] = key.to_bytes(4, 'big')
                    self.byte_array[page_start + i + 4:page_start + i + 8] = value.to_bytes(4, 'big')
                    return
                elif stored_key == key:
                    # Key exists, update the value
                    self.byte_array[page_start + i + 4:page_start + i + 8] = value.to_bytes(4, 'big')
                    return
            
            # If no space in the page, raise an error
            raise RuntimeError("Page full, cannot insert key")

    def get(self, key):
        if key == -1:
            return int.from_bytes(self.byte_array[9:13], 'big') if self.byte_array[8] == 1 else 0
        elif key == 0:
            return int.from_bytes(self.byte_array[14:18], 'big') if self.byte_array[13] == 1 else 0
        else:
            # General case: find the page and retrieve the value
            page_index = key % self.num_pages
            page_start = 18 + (self.page_size * page_index)
            
            for i in range(0, self.page_size, 8):
                key_bytes = self.byte_array[page_start + i:page_start + i + 4]
                stored_key = int.from_bytes(key_bytes, 'big')
                if stored_key == key:
                    return int.from_bytes(self.byte_array[page_start + i + 4:page_start + i + 8], 'big')
                elif stored_key == 0:
                    return 0  # End of records
            return 0

    def delete(self, key):
        if key == -1:
            # Delete key -1
            self.byte_array[8] = 0  # Set flag to 0
            self.byte_array[9:13] = (0).to_bytes(4, 'big')  # Reset value to 0
        elif key == 0:
            # Delete key 0
            self.byte_array[13] = 0  # Set flag to 0
            self.byte_array[14:18] = (0).to_bytes(4, 'big')  # Reset value to 0
        else:
            # General case: find the page and delete the value
            page_index = key % self.num_pages
            page_start = 18 + (self.page_size * page_index)
            
            for i in range(0, self.page_size, 8):
                key_bytes = self.byte_array[page_start + i:page_start + i + 4]
                stored_key = int.from_bytes(key_bytes, 'big')
                if stored_key == key:
                    # Mark the key as -1 and reset the value to 0
                    self.byte_array[page_start + i:page_start + i + 4] = (-1).to_bytes(4, 'big', signed=True)
                    self.byte_array[page_start + i + 4:page_start + i + 8] = (0).to_bytes(4, 'big')
                    return

    def dump(self):
        # Convert byte array into hex representation and format as specified
        page_size_hex = self.byte_array[0:4].hex()
        num_pages_hex = self.byte_array[4:8].hex()
        flag_neg1 = self.byte_array[8:9].hex()
        value_neg1 = self.byte_array[9:13].hex()
        flag_0 = self.byte_array[13:14].hex()
        value_0 = self.byte_array[14:18].hex()
        
        pages = []
        for i in range(self.num_pages):
            page_start = 18 + (self.page_size * i)
            page = []
            for j in range(0, self.page_size, 8):
                key = int.from_bytes(self.byte_array[page_start + j:page_start + j + 4], 'big')
                value = int.from_bytes(self.byte_array[page_start + j + 4:page_start + j + 8], 'big')
                page.append(f"{key:08x}:{value:08x}")
            pages.append(f"[{','.join(page)}]")
        
        # Print the formatted output
        print(f"{page_size_hex} {num_pages_hex} {flag_neg1} {value_neg1} {flag_0} {value_0} {' '.join(pages)}")

# Main loop to process commands
def main():
    hashmap = PrimitiveHashMap()

    while True:
        command = input().split()
        if command[0].upper() == "INIT":
            page_size = int(command[1])
            num_pages = int(command[2])
            hashmap.init(page_size, num_pages)
        elif command[0].upper() == "PUT":
            key = int(command[1])
            value = int(command[2])
            hashmap.put(key, value)
        elif command[0].upper() == "GET":
            key = int(command[1])
            print(hashmap.get(key))
        elif command[0].upper() == "DELETE":
            key = int(command[1])
            hashmap.delete(key)
        elif command[0].upper() == "DUMP":
            hashmap.dump()

if __name__ == "__main__":
    main()
