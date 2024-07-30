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

        // We only need one O(log n) operation to look up the first element
        auto it = m_map.lower_bound(keyEnd);
        
        if(it == m_map.begin()){
            if(m_valBegin == val){
                return;
            }
            else{
                if((it == m_map.end()) || (keyEnd < it -> first)){
                    m_map.emplace_hint(it, keyEnd, m_valBegin);
                    --it;
                }
                m_map.emplace_hint(it, keyBegin, val);
                return;
            }
        }
        else{
            if((it == m_map.end()) || (keyEnd < it -> first)){
                auto next_to_last = it;
                --it;
                m_map.emplace_hint(next_to_last, keyEnd, it -> second);
            }
            else{
                --it;
            }
        }

        while(!(it == m_map.begin()) && !(it -> first < keyBegin)){
            auto prev = it;
            --it;
            m_map.erase(prev);
        }

        if(it -> first < keyBegin){
            ++it;
            m_map.emplace_hint(it, keyBegin, val);
        }
        else if(keyBegin < it -> first){
            m_map.emplace_hint(it, keyBegin, val);
            m_map.erase(it);
        }
        else{
            it -> second = val;
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
