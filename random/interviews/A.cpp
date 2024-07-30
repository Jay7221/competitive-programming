int result(vector<int>&v){

	for(int i=0;i<v.size();i++){
		if((v[i]<0){
           v[i]=v[i]*-1;   
		}
	}
	int m=INT_MAX,n=INT_MAX;
	for(int i=0;i<v.size();i++){
        m=min(m,v[i]);
        if(v[i]>	m){
        	n=min(n,v[i]);
        }
	}
}