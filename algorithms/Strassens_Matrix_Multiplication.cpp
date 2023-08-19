#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > add(vector<vector<int> > A, vector<vector<int>> B){
	int n = A.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			A[i][j] = A[i][j] + B[i][j];
		}
	}
	return A;
}
vector<vector<int> > sub(vector<vector<int> > A, vector<vector<int>> B){
	int n = A.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			A[i][j] = A[i][j] - B[i][j];
		}
	}
	return A;
}
vector<vector<int> > multiply(vector<vector<int>> &A, vector<vector<int>> &B){
	int n = A.size();
	int n1 = n / 2, n2 = n / 2;
	vector<vector<int>> C(n, vector<int>(n));
	if(n == 1){
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	vector<vector<int> > A11(n1, vector<int>(n1)), A12(n1, vector<int>(n2)), A21(n2, vector<int>(n1)), A22(n2, vector<int>(n2));
	vector<vector<int> > B11(n1, vector<int>(n1)), B12(n1, vector<int>(n2)), B21(n2, vector<int>(n1)), B22(n2, vector<int>(n2));
	vector<vector<int> > C11(n1, vector<int>(n1)), C12(n1, vector<int>(n2)), C21(n2, vector<int>(n1)), C22(n2, vector<int>(n2));
	for(int i = 0; i < n / 2; ++i){
		for(int j = 0; j < n / 2; ++j){
			A11[i][j] = A[i][j];
			B11[i][j] = B[i][j];

			A12[i][j] = A[i][j + n / 2];
			B12[i][j] = B[i][j + n / 2];

			A21[i][j] = A[i + n / 2][j];
			B21[i][j] = B[i + n / 2][j];

			A22[i][j] = A[i + n / 2][j + n / 2];
			B22[i][j] = B[i + n / 2][j + n / 2];
		}
	}
	vector<vector<int> > S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	vector<vector<int> > P1, P2, P3, P4, P5, P6, P7;
	S1 = sub(B12, B22);
	S2 = add(A11, A12);
	S3 = add(A21, A22);
	S4 = sub(B21, B11);
	S5 = add(A11, A22);
	S6 = add(B11, B22);
	S7 = sub(A12, A22);
	S8 = add(B21, B22);
	S9 = sub(A11, A21);
	S10 = add(B11, B12);

	P1 = multiply(A11, S1);
	P2 = multiply(S2, B22);
	P3 = multiply(S3, B11);
	P4 = multiply(A22, S4);
	P5 = multiply(S5, S6);
	P6 = multiply(S7, S8);
	P7 = multiply(S9, S10);

	C11 = add(P5, P4);
	C11 = sub(C11, P2);
	C11 = add(C11, P6);

	C12 = add(P1, P2);
	C21 = add(P3, P4);

	C22 = add(P5, P1);
	C22 = sub(C22, P3);
	C22 = sub(C22, P7);

	for(int i = 0; i < n / 2; ++i){
		for(int j = 0; j < n / 2; ++j){
			C[i][j] = C11[i][j];
			C[i][j + n / 2] = C12[i][j];
			C[i + n / 2][j] = C21[i][j];
			C[i + n / 2][j + n / 2]  = C22[i][j];
		}
	}
	return C;
}
void input(vector<vector<int> > &A){
	int n = A.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> A[i][j];
	}
}
void output(vector<vector<int> > &A){
	int n = A.size();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << A[i][j] << ' ' ;
		cout << endl;
	}
	cout << endl;
}
int main(){
	int n;
	cout << "Enter the size of the matrices : ";
	cin >> n;
	vector<vector<int> > A(n, vector<int>(n)), B(n, vector<int>(n));
	cout << "Enter the First Matrix : " << endl;
	input(A);
	cout << "Enter the Second Matrix : " << endl;
	input(B);
	vector<vector<int> > C = multiply(A, B);
	cout << "The multiplication of the matrices is : " << endl;
	output(C);
	return 0;
}
