// Key class
class Key {
public:
    int value;

    // Constructor
    Key(int val) : value(val) {}
    Key(const Key &k){
        value = k.value;
    }

    // Less-than comparison operator
    bool operator<(const Key& other) const {
        return value < other.value;
    }
};

// Value class
class Value {
public:
    int value;

    // Constructor
    Value(int val) : value(val) {}
    Value(const Value &val){
        value = val.value;
    }

    // Equality comparison operator
    bool operator==(const Value& other) const {
        return value == other.value;
    }
};

