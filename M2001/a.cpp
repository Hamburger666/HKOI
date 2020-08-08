#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, dm, outd;
    string m, nextm, outm;
    cin >> m >> d;
    outd = d + 14;
    
    //The Following um... lines are PURE CHEESE
    if(m=="JAN"){
        outm = "JAN";
        nextm = "FEB";
        dm = 31;
        goto brak;
    }
    if (m=="FEB"){
        outm = "FEB";
        nextm = "MAR";
        dm = 29;
        goto brak;
    }
    if (m=="MAR"){
        outm = "MAR";
        nextm = "APR";
        dm = 31;
        goto brak;
    }
    if (m=="APR"){
        outm = "APR";
        nextm = "MAY";
        dm = 30;
        goto brak;
    }
    if (m=="MAY"){
        outm = "MAY";
        nextm = "JUN";
        dm = 31;
        goto brak;
    }
    if (m=="JUN"){
        outm = "JUN";
        nextm = "JUL";
        dm = 30;
        goto brak;
    }
    if (m=="JUL"){
        outm = "JUL";
        nextm = "AUG";
        dm = 31;
        goto brak;
    }
    if (m=="AUG"){
        outm = "AUG";
        nextm = "SEP";
        dm = 31;
        goto brak;
    }
    if (m=="SEP"){
        outm = "SEP";
        nextm = "OCT";
        dm = 30;
        goto brak;
    }
    if (m=="OCT"){
        outm = "OCT";
        nextm = "NOV";
        dm = 31;
        goto brak;
    }
    if (m=="NOV"){
        outm = "NOV";
        nextm = "DEC";
        dm = 30;
        goto brak;
    }
    if (m=="DEC"){
        outm = "DEC";
        nextm = "JAN";
        dm = 31;
        goto brak;
    }
    /*
    All the goto I used are functionally 
    same as the "break"s in a switch function 
    but you can't switch string type varibles
    Q3Q
    */
    
    //Cheesing complete. now bacc to normal code
    brak:
    if(outd>dm){
        outd -= dm;
        cout << nextm << " " << outd;
    }
    else{
        cout << outm << " " << outd;
    }
}
