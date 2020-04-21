#include "hash.h"
#include <string>
#include<iostream>
using namespace std;


//table size = 40009
//linear probing
//quadratic probing
//chaining with LL

//CONSTRUCTOR
HashTable::HashTable(int size){
    tableSize = 40009;
}


///////////////////////////////////////// LL CHAINING ///////////////////////////////////////////

bool HashTable:: insertItem(int key){ //LL chaining implementation
    int index= hashFunction(key); //retrieve index from hash fxn
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    hashElement->next = NULL;

    if(table[index]==NULL){
        hashElement->prev = NULL; //?
        table[index] = hashElement;
    }else{
        node*temp = table[index];
        while(temp!=NULL){
            numOfcolision++;
            if(temp->key == key){
                return false;
            }
            temp = temp->next; //keep going
        }
        temp = table[index];
        while(temp!=NULL && hashElement->key>temp->key){
            temp = temp->next;
        }

        hashElement->next = temp;
        hashElement->prev = temp->prev;
        temp->prev->next = hashElement;
        temp->prev = hashElement;

    }

    return true;

}

//search via LL chaining
node * HashTable:: searchItemLL(int key){
    bool found = false;
    int index = hashFunction(key); //index from hash fxn
    node * search = table[index];

    while(search!=NULL){
        if(search->key ==key){
            cout<<"found key " << key<<endl;
            found = true;
        }
        
        search = search->next;

    }

    if(!found){
        cout<<"key "<<key<<" not found"<<endl;
        return NULL;
    }

}


 
///////////////////////////////////////// LINEAR PROBING ///////////////////////////////////////////

//insert via linear probing
void HashTable:: linearProb(int key){ 
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    int index = hashFunction(key);
    while(table[index]!=NULL){
        numOfcolision++;
        index++;
        if(index==tableSize-1){
            index = 0;
        }
    }

    table[index] = hashElement;

    //cout<<"Table is full. Cannot insert"<<endl;
}

//search via linear probing
node * HashTable:: searchItemLinear(int key){
    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+i)%tableSize]->key==key){
            return table[(hashFunction(key)+i)%tableSize];
        }
    }

    cout<<"Item not found"<<endl;
    return NULL;
}



///////////////////////////////////////// QUADRATIC PROBING ///////////////////////////////////////////
 
//insert via quadratic probing
void HashTable:: quadraticProb(int key){ 
    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;
    
    int i= hashFunction(key); //index 
    int index = i;
    int a = 1;
    while(table[index]!=NULL){ //while table at index is occupied
        numOfcolision++;
        index=i+(a*a); //change index
        a++;
    }

    table[index] = hashElement; //finally insert the new node at calculated index
}


//search via quadratic probing
node * HashTable:: searchItemQuadtratic(int key){
    int i= hashFunction(key);
    int index = i;
    int a = 1;
    node* result = NULL;
    while(table[index]->key!=key){
        numOfcolision++;
        index=i+(a*a);
        a++;
    }

    result = table[index];
    return result; 

}





/////////////////////////////////////////////////////////////////////////////


//DIVISION METHOD
unsigned int HashTable:: hashFunction(int key){ 
        return key%tableSize; //index

}

void HashTable:: printTable(){

    for(int i=0; i<tableSize;i++){
        cout<<table[i]->key<<" "<<endl;
    }


}


int HashTable:: getNumOfCollision(){
    return numOfcolision;
}



