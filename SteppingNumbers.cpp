/*
Given N and M, find all stepping numbers in the range N to M. Return the numbers in sorted order. 

A number is called a stepping number, if all of its adjacent digits have a difference of 1 
e.g. 123 is a stepping number but 122 is not. 
  
Note: All single digit numbers are stepping numbers. 

N = 10, M = 20
Output: 10, 12

N = 100, M = 200
Output: 101 121 123 
*/

#define ll long long

vector<ll> stepnum (ll lb, ll ub){
    vector<ll> result;

    if (lb==0) result.push_back(0);

    for (int digit=1; digit<=9; digit++){
        queue <ll> q;

        q.emplace(digit);

        while (!q.empty()){
            ll n = q.front();

            q.pop();

            if (n >= lb && n <= ub){
                result.push_back(n);
            }

            int ld = n%10;

            if (ld != 9){
                ll n1 = n*10+(ld+1);

                if (n1 <= ub){
                    q.emplace(n1);
                }
            }

            if (ld != 0){
                ll n2 = n*10+(ld-1);

                if (n2 <= ub){
                    q.emplace(n2);
                }
            }
        }
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    ll lb, ub;
    cin >> lb >> ub;

    vector<ll> result = stepnum(lb, ub);

    for (auto i: result){
        cout << i << " ";
    }

    cout << endl;
}
  
