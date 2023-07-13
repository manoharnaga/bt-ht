#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;
#define MOD 1000000007

int main(){
    //NO ADT IS REQUIRED FOR THIS QUESTION
    ll n,t;
    scanf("%lld %lld",&n,&t);
    ll level = ((n-1)/2) + 1;
    ll maxlevel = level;
    // tnode* root = NULL;
    // root = insert(root,val/2);
    // root = build(root,val/2);
    ll x=0;
    ll temp1=0,temp2=0;
    char str[100010];
    while(t--){
        scanf("%lld %s",&x,str);
        while(x%level!=0){
            level/=2;
        }
        // level*=2;
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='U'){
                if(level==(maxlevel/2)){
                    level = maxlevel;
                    x = maxlevel;
                }
                else if(level<maxlevel){//IF U COMES ON MAXLEVEL NO CHANGE
                    temp1 = x-level;
                    temp2 = x+level;
                    if(temp1%(level*4)==0){
                        x = x+level;
                    }
                    else if(temp2%(level*4)==0){
                        x = x-level;
                    }
                    level*=2;
                }
                // printf("Level: %lld x: %lld\n",level,x);
            }
            else if(str[i]=='L'){
                if(level>1){
                    level/=2; //one level down
                    x = x - level;
                }
                // printf("Level: %lld x: %lld\n",level,x);
            }
            else if(str[i]=='R'){
                if(level>1){
                    level/=2; //one level down
                    x = x + level;
                }
                // printf("Level: %lld x: %lld\n",level,x);
            }
        }
        printf("%lld\n",x);
        level = maxlevel;
    }
    return 0;
}