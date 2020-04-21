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
    //initialize table
    for(int i=0; i<tableSize; i++){
        table[i]=NULL;
    }
}


///////////////////////////////////////// LL CHAINING ///////////////////////////////////////////

bool HashTable:: LLChaining(int key){ //LL chaining implementation
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
                cout<<"Duplicate found"<<endl;
                return true;
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
//traverse entire LL: worst case = O(N)
node * HashTable:: searchItemLL(int key){
    bool found = false;
    int index = hashFunction(key); //index from hash fxn
    node * search = table[index];

    while(search!=NULL){
        if(search->key ==key){
            cout<<"found key " << key<<endl;
            found = true;
            return search; //return node found with correct key value
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
bool HashTable:: linearProb(int key){ 

    node*hashElement = new node; //pointer to new value to be inserted
    hashElement->key = key;

    for(int i=0 ;i<tableSize;i++){
        if(table[(hashFunction(key)+i) % tableSize]==NULL){
            table[(hashFunction(key)+i) % tableSize]= hashElement;
            cout<<"Insert successful"<<endl;
            return true;
        }
        numOfcolision++;
    }
    

    cout<<"Table is full. Cannot insert"<<endl;
    return false;
}

//search via linear probing
node * HashTable:: searchItemLinear(int key){

    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+i)%tableSize]->key==key){
            cout<<"Item found"<<endl;
            return table[(hashFunction(key)+i)%tableSize];
        }


    }

    cout<<"Item not found"<<endl;
    return NULL;
}



///////////////////////////////////////// QUADRATIC PROBING ///////////////////////////////////////////
 
//insert via quadratic probing
bool HashTable:: quadraticProb(int key){ 
    node*hashElement = new node; 
    hashElement->key = key;

    for(int i=0 ;i<tableSize;i++){
        if(table[(hashFunction(key)+(i*i)) % tableSize]==NULL){
            table[(hashFunction(key)+(i*i)) % tableSize]= hashElement;
            cout<<"Insert successful"<<endl;
            return true;
        }
        numOfcolision++;
    }
    

    cout<<"Table is full. Cannot insert"<<endl;
    return false;
}


//search via quadratic probing
node * HashTable:: searchItemQuadtratic(int key){
    for(int i=0; i<tableSize;i++){
        if(table[(hashFunction(key)+(i*i))%tableSize]->key==key){
            cout<<"Item found"<<endl;
            return table[(hashFunction(key)+(i*i))%tableSize];
        }
    }

    cout<<"Item not found"<<endl;
    return NULL;

}





/////////////////////////////////////////////////////////////////////////////


//DIVISION METHOD
unsigned int HashTable:: hashFunction(int key){ 
        return key%tableSize; //index

}

void HashTable:: printTable(){

    for(int i=0; i<tableSize;i++){
        cout<<table[i]->key<<" ";
    }

    cout<<endl;


}


int HashTable:: getNumOfCollision(){
    return numOfcolision;
}


