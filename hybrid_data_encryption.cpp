#include<bits/stdc++.h>
using namespace std;

string fibonaciEncrypt(string message,int length); 
string XORencrypt(string message,int length , int key);
string PNencrypt(string message,int length,int arr[]);

string fibonaciDencrypt(string encrypt , int length);
string XORdencrypt(string encrypt , int length , int key);
string PNdencrypt(string encrypt ,int length , int arr[]);

int main()  {
    string message ;
    cout << "Enter the message";            
    getline(cin , message);         //Taking the message as input
    cout << "The orignal message is : " << message << "\n" ;
    //Encryption
    int len = message.length();
    int len1 = len/3;
    int len2 = len/3;
    int len3 = len - len1 - len2;

    string message1 = message.substr(0,len1);              //Dividing the message
    string message2 = message.substr(len1,len2);            //in three parts
    string message3 = message.substr(len1+len2,len3);

    srand(time(0));
    int key = rand()%256;           //randomly generated key

    int PNsequence[len3];           //array of random generated numbers
    for(int i = 0 ; i < len3 ; i++) {
        PNsequence[i] = rand()%256;
    }

    string encrypt1 = fibonaciEncrypt(message1 , len1);     //encrypting first part
    string encrypt2 = XORencrypt(message2,len2,key);        //encrypting second part
    string encrypt3 = PNencrypt(message3,len3,PNsequence);  //encrypting third part
    
    string encrypt = encrypt1 + encrypt2 + encrypt3 ;       //combing the encrypted parts
    cout << "The encrypted message after hybrid encryption is : " << encrypt << endl;

    //Message is delivered in this form
    //Dencryption

    len = encrypt.length();
    len1 = len/3;
    len2 = len/3;
    len3 = len - len1 - len2;

    string encrypt_1 = encrypt.substr(0,len1);             //Dividing the encrypted message
    string encrypt_2 = encrypt.substr(len1,len2);           //into 3 parts
    string encrypt_3 = encrypt.substr(len1+len2,len3);

    string dencrypt1 = fibonaciDencrypt(encrypt_1,len1);    //dencrypting the first part
    string dencrypt2 = XORdencrypt(encrypt_2 , len2 , key);  //dencrypting the second part
    string dencrypt3 = PNdencrypt(encrypt_3 , len3 , PNsequence);   //dencrypting the third part

    string dencrypt = dencrypt1 + dencrypt2 + dencrypt3 ;    //orignal dencrypted message
    cout << "The message after dencryption will be : " << dencrypt;

    return 0;
}

string fibonaciEncrypt(string message , int length) {
    string  encrypt1 = "";
    int prev_term = 0 ,curr_term = 1 , incr = 1;

    for(int i = 0 ; i < length ; i++)  {
        encrypt1 += (message[i] + curr_term)%256;
        incr = curr_term;
        curr_term += prev_term;
        prev_term = incr;
    }
    return encrypt1;
}

string XORencrypt(string message , int length , int key)  {
    string encrypt2 = "";
    for(int i = 0 ; i < length ; i++)   {
        encrypt2 += ((message[i]^key)%256);
    }
    return encrypt2;
}

string PNencrypt(string message , int length , int PNsequence[])   {
    string encrypt3 = "";
    for(int i = 0 ; i < length ; i++)   {
        encrypt3 += ((message[i]^PNsequence[i])%256);
    }
    return encrypt3;
}

string fibonaciDencrypt(string message , int length) {
    string  encrypt1 = "";
    int prev_term = 0 ,curr_term = 1 , incr = 1;

    for(int i = 0 ; i < length ; i++)  {
        encrypt1 += (message[i] - curr_term)%256;
        incr = curr_term;
        curr_term += prev_term;
        prev_term = incr;
    }
    return encrypt1;
}

string XORdencrypt(string encrypt , int length , int key)  {
    string dencrypt2 = "";
    for(int i = 0 ; i < length ; i++)   {
        dencrypt2 += ((encrypt[i]^key)%256);
    }
    return dencrypt2;
}

string PNdencrypt(string encrypt , int length , int PNsequence[])   {
    string dencrypt3 = "";
    for(int i = 0 ; i < length ; i++)   {
        dencrypt3 += ((encrypt[i]^PNsequence[i])%256);
    }
    return dencrypt3;
}