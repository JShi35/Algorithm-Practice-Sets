#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class UF{

public:

    unordered_map<string, string> network;
    unordered_map<string, int> networkSize;

    void make_network(string& person){
        if (network.find(person) == network.end())
        {
            network[person] = person;
            networkSize[person] = 1;
        }
    }
    string find(string& person){
        if(network[person] != person){
            network[person] = find(network[person]);
        }
        return network[person];
    }

    void unite(string& person1, string& person2){
        string parent1 = find(person1);
        string parent2 = find(person2);

        if (parent1 != parent2)
        {
            if (networkSize[parent1]<networkSize[parent2])
            {
                network[parent1] = parent2;
                networkSize[parent2] += networkSize[parent1];
            }else{
                network[parent2] = parent1;
                networkSize[parent1] += networkSize[parent2];
            }
            
        }
        
    }

        int getSize(string& person){
            return networkSize[find(person)];
        }
};

int main() {
    int test_cases;
    int friendshipNum;
    cin >> test_cases;

    while (test_cases--) {
        cin >> friendshipNum;
        UF uf;

        for (int i = 0; i < friendshipNum; ++i) {
            string friend1;
            string friend2;
            cin >> friend1 >> friend2;

       
            uf.make_network(friend1);
            uf.make_network(friend2);

            uf.unite(friend1, friend2);
            cout << uf.getSize(friend1) << endl;
        }
    }

    return 0;
}