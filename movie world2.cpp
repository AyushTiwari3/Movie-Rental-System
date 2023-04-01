#include <iostream>
using namespace std;

class movies {

    protected :
    int no_of_movies;
    string *movie;
    float *price;
    int *quantity;
    int *age;
    public :

    void set_number ();
    void set_movies_info();
   

    movies (){

        set_number ();
        movie = new string [no_of_movies];
        price = new float [no_of_movies];
        quantity = new int [no_of_movies];
        age = new int [no_of_movies];
        set_movies_info ();
    }

};

void movies :: set_number (){

    cout<<"Enter the number of movies in the shop ---> ";
    cin>>no_of_movies;

    cout<<endl<<"Number of movies are set !"<<endl;
}

void movies :: set_movies_info (){

    cout<<endl<<"Enter the movies information ---> "<<endl;

    for (int i=0;i<no_of_movies ; i++){

        while (getchar ()!='\n');
        cout<<endl<<"Enter the details of movie number: "<<i+1<<endl;
        cout<<"Enter the name of movie (IN UPEER CASE) ---> ";

        getline (cin, movie[i]);
        
        cout<<"Enter the price of the movie ---> ";
        cin>>price [i];
        cout<<"Enter the quantity of the movie available in the store ---> ";
        cin>>quantity [i];
        cout<<"Enter the age group for the movie: \nset 1 for 18+ movie / set 0 for all age group --> ";
        cin>>age[i];
    }

    cout<<endl<<"Movies info are set !"<<endl<<endl;
}



class shop : protected movies{
    protected :

    float balance;
    float profit = 0;

    public :
    void set_balance ();

    shop (){
        cout<<"Shop is now Open !"<<endl;
        set_balance ();
    }
    void update_movies ();
    void shop_close ();
    void fill_shop ();
    void get_details_of_shop ();
    void get_bal_profit ();
    void final_credits ();

    ~shop (){
        shop_close ();
        final_credits ();
    }

};

void shop :: final_credits (){
    cout<<endl<<"This program is made by -- >"<<endl;
    cout<<"\t**MOHIT SHARMA\t 0901CS211069**"<<endl;
    cout<<"\t**AYUSH TIWARI\t 0901CS211034**"<<endl;
    cout<<"\t**RAHUL RAWAT\t 0901CS211090**"<<endl;
    cout<<"\t**SHRUTI SINGAL\t 0901CS211108**"<<endl;
    cout<<"\t**POOJA BAGHEL\t 0901CS211084**"<<endl;
}

void shop :: set_balance (){
    cout<<"Enter the current balance of the shop ---> ";
    cin>>balance;

    cout<<"Shop balance set !"<<endl;
}

void shop :: get_bal_profit (){
    cout<<"The available balance of the shop is --> "<<balance<<endl;
    if (profit < 0){
        cout<<"The loss is --> "<<-profit<<endl;
    }

    else{
        cout<<"The profit is --> "<<profit<<endl;
    }
}

void shop :: shop_close (){
    cout<<endl<<"Finally the Day ended !"<<endl;
    cout<<"Balance is --> "<<balance<<endl;

    if (profit == 0){
        cout<<endl<<"The day was ideal :) .. No profit earned !"<<endl;
    }

    else if (profit > 0){
        cout<<endl<<"The day was lucky ;) .. Total profit earned is: "<<profit<<endl;
    }

    else{
        cout<<endl<<"The day was unlucky :( .. Total loss was: "<<-profit<<endl;
    }
}

void shop :: fill_shop (){
    int total_buy, quanti ,d = 0, total_to_pay = 0;

    get_details_of_shop ();
    cout<<endl<<"Enter the number of different movies you want to buy for the shop --> ";
    cin>>total_buy;

    string buying_movie;

    for (int i = 0 ;i <total_buy ;i++){

        while (getchar ()!='\n');
        cout<<"Enter the name of the movie "<<i+1<<" to buy (IN UPPER CASE) --> ";
        getline (cin , buying_movie);


        for (int j = 0 ;j<no_of_movies ;j++){
            if (movie[j] == buying_movie){
                cout<<"Enter the quantity of the movie you want to buy --> ";
                cin>>quanti;

                quantity [j] = quantity [j] + quanti;
                balance = balance - price [j]*0.5*quanti; 
                profit = profit - price [j]*0.5*quanti;
                total_to_pay = total_to_pay + price[j]*0.5*quanti;
                d++ ;

            }
        }
        if (d == 0){
        cout<<endl<<"The shop do not sell that movie !"<<endl;
        }
        d = 0;

    }

    cout<<endl<<"You have to pay a total of "<<total_to_pay<<" Rs to buy them !"<<endl;
    
}

void shop :: update_movies (){
    string ab;
    int x = 0;

    get_details_of_shop ();

    cout<<endl<<"Enter the name of movie whose price you want to update (IN UPPER CASE) --> ";
    getline (cin, ab);

    for (int i=0;i < no_of_movies ;i++){

        if (ab == movie[i]){
            cout<<"Enter the updated price of the movie --> ";
            cin>>price [i];
            x++;
        }
    }

    if (x == 0){
        cout<<"The movie is not available in the shop !"<<endl;
    }
}

void shop :: get_details_of_shop (){

    cout<<endl<<"The details of the movies in the shop are --> "<<endl;
    for (int i = 0 ;i<no_of_movies ;i ++){
        if (quantity[i] == 0){
            cout<<movie[i]<<" is sold out !"<<endl;
        }
        
        else {
            cout<<"Name --- >"<<movie[i]<<"  ";
            cout<<"Price ---> "<<price[i]<<"  ";
            cout<<"Quantity -- > "<<quantity[i]<<"  ";
            if (age[i] == 1)
                cout<<"Age group --> 18+"<<endl;
            else 
                cout<<"Age group --> Everyone"<<endl;
        }
    }
}

class buyer_operation : public shop {
    public :

    buyer_operation (){};
    void buy_movie (float, int );
    void rent_movie (float, int );
    void return_movie (string, int, float);

};

void buyer_operation :: buy_movie (float visit, int aging){

    string buy;
    float discount = visit / 100;
    float fix_discount = discount;
    int num_of_mov;
    int data = 0;
    float total_discount = 0;

    get_details_of_shop ();

    cout<<"Enter the number of movies you want to buy --> ";
    cin>>num_of_mov;
    float price_movie[num_of_mov] = {0};
    string bought_moves[num_of_mov];

    while (getchar ()!='\n');

    for (int k = 0;k <num_of_mov ;k ++){
        cout<<"Enter the name of the movie "<<k+1<<" (IN UPPER CASE) --> ";
        getline (cin, buy);

        for (int i= 0;i<no_of_movies ;i++){

            if (buy == movie[i]){
                if (age[i] ==1 && aging < 18) {
                    cout<<endl<<"This movie is not availabe for your age group !"<<endl<<endl;
                    bought_moves[k] = buy;
                    price_movie[k] = 0;
                    break ;
                }

                if (quantity[i] !=0) {

                    discount = price[i]*fix_discount;
                    total_discount = discount + total_discount;
                    // cout<<" discorunt "<<discount<<endl;
                    profit = profit + price [i] - discount;

                    balance = balance + price [i] - discount;

                    price_movie[k] = price [i] - discount;

                    bought_moves[k] = buy;
                    quantity[i]--;
                    data ++ ;
                    break;
                }
                else{
                    cout<<"Sorry that movie is sold out !"<<endl;
                    bought_moves[k] = buy;
                    price_movie[k] = 0;
                    break;
                }
            }
            else if (i == no_of_movies-1){
                cout<<"Sorry we do not sell this movie !"<<endl;
                bought_moves[k] = buy;
            }
        }
    }
    if (data == 0){

        cout<<"Sorry we do not sell the required movie !"<<endl;
        return ;
    }
    float total = 0;

    cout<<endl<<"YOUR BILL IS PREPARED !"<<endl;
    cout<<"Movie and price are --> "<<endl<<endl;

    for (int i=0;i<num_of_mov;i++){
        if (price_movie[i] == 0){
            cout<<"Movie --- > "<<bought_moves[i]<<" is not available !"<<endl<<endl;
        }

        else {
            cout<<"Movie --- > "<<bought_moves[i]<<"  "<<"price of movie --> "<<price_movie[i]<<endl<<endl;
            total = price_movie[i] + total;
        }
    }

    cout<<"Total discount is: "<<total_discount<<endl;
    cout<<"Please pay a sum of ---> "<<total<<" Rupees"<<endl;

    cout<<endl<<"Press Enter to continue ... ";
    getchar ();

};

void buyer_operation :: rent_movie (float visit, int aging){
    buy_movie(visit,aging);
}

void buyer_operation :: return_movie (string movie_name, int amount, float visit){
    float discount = 20 + visit;
    discount = discount / 100;
    for (int i = 0 ;i<no_of_movies ;i ++){

        if (movie[i] == movie_name){
            balance = balance - price[i]*discount*amount;
            profit = profit - price[i]*discount*amount;
            quantity[i] = quantity[i] + amount;

            cout<<endl<<"Please take the return money of "<<discount*100<<"% of base price: "<<price[i]*discount*amount<<endl;
            cout<<"Press Enter to continue....";
            getchar ();
            return ;
        }
    }

    cout<<"Sorry we do not accept this movie !"<<endl;
}

class buyer : public buyer_operation {
    protected :
    string buyers_list[100];
    int age_list [100];
    float visits[100] = {0};
    int counter = 0;
    public :
    void set_buyer_data ();

    int check_new_buyer (string);
    void go_to_buy();
    void go_to_rent ();
    void go_to_return_movie ();
};

void buyer :: set_buyer_data (){
    string h;
    cout<<endl<<"New Buyer !"<<endl;
    cout<<"Please register the buyer in the server: "<<endl;
    cout<<"Enter the name of the buyer: ";
    // while (getchar ()!='\n');
    getline (cin, buyers_list[counter]);
    cout<<"Enter the age of the buyer: ";
    cin>>age_list [counter];
    while (getchar ()!='\n');
    counter = counter + 1;
}

int buyer :: check_new_buyer (string a){

    for (int i = 0 ;i <= counter ;i++){
        if (buyers_list[i] == a){
            visits[i] ++ ;
            // cout<<" jai "<<visits[i]<<endl;
            return i;
        }
    }

    set_buyer_data ();
    
    return counter-1;
}

void buyer :: go_to_buy (){
    string test;
    cout<<"Enter the name of the buyer: ";
    while (getchar ()!='\n');
    getline (cin , test);

    int index = check_new_buyer (test);
    
    
    if (visits[index] == 0){
        buy_movie (0, age_list[index]);
    }
    else {
        if (visits[index] > 5){
            buy_movie (5, age_list [index]);
        }
        else{
            // cout<<" kaka "<<visits[index]<<endl;
            buy_movie (visits[index], age_list[index]);
        }
    }
}

void buyer :: go_to_rent (){
    string test;
    cout<<"Enter the name of the buyer: ";
    while (getchar ()!='\n');
    getline (cin , test);

    int index = check_new_buyer (test);
    if (visits[index] == 0){
        rent_movie (0, age_list [index]);
    }
    else {
        if (visits[index] > 5){
            rent_movie (5, age_list[index]);
        }
        else{
            rent_movie (visits[index], age_list [index]);
        }
    }
}

void buyer :: go_to_return_movie (){
    string test, boo_name;
    int amount;
    cout<<"Enter the name of the buyer: ";
    while (getchar ()!='\n');
    getline (cin , test);

   
    int index = check_new_buyer (test);


    cout<<"Enter the name of the movie you want to return: ";
    // while (getchar ()!='\n');
    getline (cin, boo_name);
    cout<<"Enter the number of movie you want to return: ";
    cin>>amount;
    
    return_movie (boo_name, amount, visits[index]);
    
}

int main (){

    cout<<"\t\t\t\t*********HELLO AND WELCOME TO MOVIE WORLD !**************"<<endl;
    cout<<endl<<"\t\t\t\tLets start by entering the details of your shop: "<<endl<<endl;
    buyer a;
    int start;
    do {
        
        cout<<endl<<"Enter the operation you want to perform: "<<endl;
        cout<<"1 for buying a movie\n2 for taking movie on rent\n3 for returning the movie\n4 for putting stock in shop\n5 for checking details of shop\n6 for setting buyer data\n7 for updating the price list\n8 for checking current balance and profit\n9 for exitting from shop: ";
        cin>>start;

        switch (start){
            case 1:
                a.go_to_buy ();
                break;
            case 2:
                a.go_to_rent();
                break;
            case 3:
                a.go_to_return_movie();
                break;
            case 4:
                a.fill_shop ();
                break;
            case 5:
                a.get_details_of_shop ();
                break;
            case 6:
                while (getchar ()!='\n');
                a.set_buyer_data();
                break;
            case 7:
                while (getchar ()!='\n');
                a.update_movies ();
                break;
            case 8:
                a.get_bal_profit();
                break;
            case 9:
                cout<<"Thanks !"<<endl;
                break;
            default :
                cout<<"Wrong input !"<<endl;

        }
    }while (start != 9);
}