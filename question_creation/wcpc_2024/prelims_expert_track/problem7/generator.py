import os
import random

NUM_TEST_SETS = 10
MAX_TEST_CASES = 200
MAX_NUM_CITIES = 10**5
MAX_INVESTMENT = 10**6
MIN_NUM_CITIES = 1
MAX_NUM_ROADS = 2 * 10**5  # Maximum number of potential roads per test case
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.in'

def generate_test_case(test_set_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    num_test_cases = random.randint(1, MAX_TEST_CASES)
    remaining_cities = 2 * 10**5  # Remaining number of cities for potential roads
    test_cases = []  # List to hold multiple test cases
    for _ in range(num_test_cases):
        max_cities = min(remaining_cities, MAX_NUM_CITIES)  # Maximum number of cities for this test case
        max_cities = max(max_cities, MIN_NUM_CITIES)
        num_cities = random.randint(1, max_cities)  # Number of cities for this test case
        remaining_cities -= num_cities
        investment_costs = [random.randint(-MAX_INVESTMENT, MAX_INVESTMENT) for _ in range(num_cities)]  # Generate investment costs for each city
        num_roads = random.randint(0, min(num_cities*(num_cities-1)//2, MAX_NUM_ROADS))  # Number of potential roads
        roads = []
        for _ in range(num_roads):
            city_a = random.randint(1, num_cities)
            city_b = random.randint(1, num_cities)
            while city_a == city_b:
                city_b = random.randint(1, num_cities)
            road_cost = random.randint(-MAX_INVESTMENT, MAX_INVESTMENT)
            roads.append((city_a, city_b, road_cost))
        test_cases.append((num_cities, investment_costs, num_roads, roads))
    return num_test_cases, test_cases

def print_test_case(file_path, num_test_cases, test_cases):
    """
    Writes the test cases to a file.
    """
    with open(file_path, 'w') as file:
        file.write(str(num_test_cases) + '\n')
        for test_case in test_cases:
            num_cities, investment_costs, num_roads, roads = test_case
            file.write(str(num_cities) + '\n')
            file.write(" ".join(map(str, investment_costs)) + '\n')
            file.write(str(num_roads) + '\n')
            for road in roads:
                file.write(" ".join(map(str, road)) + '\n')

def generate_test_cases():
    """
    Generates test cases for the specified number of test case sets and writes them to files.
    """
    if not os.path.exists(INPUT_FOLDER):
        os.makedirs(INPUT_FOLDER)

    for i in range(1, NUM_TEST_SETS + 1):
        num_test_cases, test_cases = generate_test_case(i)
        file_path = os.path.join(INPUT_FOLDER, f'0{i}{INPUT_EXTENSION}')
        print_test_case(file_path, num_test_cases, test_cases)

if __name__ == "__main__":
    generate_test_cases()

