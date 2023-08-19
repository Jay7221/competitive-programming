#include<bits/stdc++.h>
using namespace std;
void solve(){
	int NUMBER_EVENTS, NUMBER_PERSONS;
	cin >> NUMBER_EVENTS >> NUMBER_PERSONS;
	vector<vector<long long> > A(NUMBER_EVENTS, vector<long long>(NUMBER_PERSONS));
	// A[event][person] = the amount of credits that person will get on attending event
	for(int event = 0; event < NUMBER_EVENTS; ++event){
		for(int person = 0; person < NUMBER_PERSONS; ++person){
			cin >> A[event][person];
		}
	}
	vector<long long> totalcredit(NUMBER_EVENTS);
	// totalcredit[event] = sum of A[event][person], i.e. the total credit that will be added if event is added to S
	for(int event = 0; event < NUMBER_EVENTS; ++event){
		for(int person = 0; person < NUMBER_PERSONS; ++person){
			totalcredit[event] += A[event][person];
		}
	}

	long long final_answer = 0;
	for(int person = 0; person < NUMBER_PERSONS; ++person){
		long long min_answer = 0, max_answer = 0;
		// min_answer = the diff if person has minimum score
		// max_answer = the diff if person has maximum score
		for(int event = 0; event < NUMBER_EVENTS; ++event){
			long long temporary = totalcredit[event] - A[event][person] * NUMBER_PERSONS;
			if(temporary > 0){
				min_answer += temporary;
			}else{
				max_answer += abs(temporary);
			}
		}
		final_answer = max({final_answer, min_answer, max_answer});
	}
	cout << final_answer << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NUMBER_TESTCASES;
	cin >> NUMBER_TESTCASES;
	for(int testcase = 1; testcase <= NUMBER_TESTCASES; ++testcase){
		solve();
	}
}