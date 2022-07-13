#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
bool testcases = false;

class Prison{
    vector<int> rooms;
    int n;
    int found=0;
    public:
        Prison(int n, int j){
            this->n = n;
            this->rooms.resize(n);
            // arrange 1-100 random in the vector
            for(int i = 0; i < n; i++){
                this->rooms[i] = i;
            }
            // random set seed
            srand(j);
            random_shuffle(this->rooms.begin(), this->rooms.end());
        }

        bool travarse(const int p){
            int i = p;
            int j = 0;
            while (j < this->n*.7 ){
                if(p == rooms[i])
                    return true;

                j++;
                i = this->rooms[i];
            }
            return false;
        }

        bool simulate(){
            int i = 0;
            while(i < n){
                if(travarse(i)){
                    this->found++;
                }
                i++;
            }
            // cout << "i: " << i << endl;
            // cout << "Found " << this->found << " rooms" << endl;
            return this->found == n;
        }


        void print(){
            for(int i = 0; i < n; i++){
                cout << this->rooms[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    for (int k = 50; k <= 50; k=k*2)
    {
        
        int n=10000;
        int count = 0;
        for (int i = 0; i < n; i++){
            Prison p(k, i+k);
            count += p.simulate();
        }
        cout << "k: " << k << " count: " << count << endl;
        cout << "Probability of success: " << (double)count/n << endl;
    }
    
    
    return 0;
}