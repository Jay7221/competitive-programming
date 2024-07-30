#include <map>
template<typename K, typename V>
class interval_map {
public:
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // Check if the interval is empty
        if(!(keyBegin < keyEnd))
        {
            return;
        }


        // First insert the keyEnd, check if there is an element before keyEnd else map it to m_valBegin
        auto prev_to_end = m_map.upper_bound(keyEnd);
        if(prev_to_end == m_map.begin()){
            m_map.emplace(keyEnd, m_valBegin);
        }
        else{
            --prev_to_end;
            m_map.emplace(keyEnd, prev_to_end -> second);
        }

        // Erase all the mappings between (keyBegin, keyEnd) excluding keyEnd
        auto first = m_map.lower_bound(keyBegin);
        auto last = m_map.lower_bound(keyEnd);
        m_map.erase(first, last);

        // Insert new mapping for keyBegin if necessary
        auto it = m_map.upper_bound(keyBegin);
        if(it == m_map.begin()){
            // If keyBegin is the smallest key, ensure the value matches m_valBegin
            if(!(m_valBegin == val)){
                m_map.emplace(keyBegin, val);
            }
        }
        else{
            --it;
            // If the previous key mapping has a different value, insert a new mapping
            if(!((it -> second) == val)){
                m_map.emplace(keyBegin, val);
            }
        }

        last = m_map.lower_bound(keyEnd);
        // Erase the last mapping if it is redundant
        if(last != m_map.begin()){
            auto prev_to_last = last;
            --prev_to_last;
            if(prev_to_last -> second == last -> second){
                m_map.erase(last);
            }
        }
        else{
            if(m_valBegin == last -> second){
                m_map.erase(last);
            }
        }
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
