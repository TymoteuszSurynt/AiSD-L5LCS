#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;
long long check;
long long check2;
int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
string readLCS(int** matrix, string a, string b,int i, int j){

    if(i==0 || j==0){
        check2++;
        return "";
    }else if(a[i-1]==b[j-1]){
        check2+=2;
        return readLCS(matrix,a,b,i-1,j-1) + a[i-1];
    }else{
        check2+=4;
        if(matrix[i][j-1]>matrix[i-1][j]){
            return readLCS(matrix,a,b,i,j-1);
        }else{
            return readLCS(matrix,a,b,i-1,j);
        }
    }
}
string LCS(string a, string b, int sizeA, int sizeB) {
    int **matrix = new int *[sizeA+1];
    for (int i = 0; i <= sizeA; ++i) {
        matrix[i] = new int[sizeB+1];
    }
    for (int j = 0; j <= sizeB; ++j) {
        matrix[0][j]=0;
    }
    for (int j = 0; j <= sizeA; ++j) {
        matrix[j][0]=0;
    }
    for (int j = 1; j <= sizeA; ++j) {
        for (int i = 1; i <= sizeB; ++i) {
            check++;
            if(a[j-1]==b[i-1]){
                matrix[j][i]=matrix[j-1][i-1]+1;
            }else{
                matrix[j][i]=max(matrix[j][i-1],matrix[j-1][i]);
            }
        }
    }
    return readLCS(matrix,a,b,sizeA,sizeB);
}
int main() {
    string a,b;
    int t;
    cout<<"Test? 1-Yes 2-No"<<endl;
    cin>>t;
    if(t==1){
        ofstream file;
        file.open("output.txt");
        srand(time(NULL));
        file << "" << "\t" << "LCS" << "\t" << "LCS-Read"<< endl;
        for (int i = 5; i <= 3000 ; i+=5) {
            a="";
            b="";
            check=0;
            check2=0;
            for (int j = 0; j < i+rand()%5; ++j) {
                a+=rand()%58+65;
            }
            for (int j = 0; j < i+rand()%5; ++j) {
                b+=rand()%58+65;
            }
            LCS(a,b,a.length(),b.length());
            file << i<< "\t" << check << "\t" << check2 << endl;
        }
        file.close();
    }else {
        cout<<"First word:"<<endl;
        cin >> a ;
        cout<<"Second word:"<<endl;
        cin>> b;
        cout <<"LCS: "<< LCS(a, b, a.length(), b.length()) << endl;
        return 0;
    }
}