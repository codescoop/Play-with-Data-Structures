/*
    Problem: Ram often uses public transport. The transport in the city is of two types: cabs and rickshaws. The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, the cabs are numbered by integers from 1 to m.
             Public transport is not free. There are 4 types of tickets:
                A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
                A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
                A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
                A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.
             Ram knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets.

    Input Format: Each Test case has 4 lines which are as follows:
                  The first line contains four integers c1, c2, c3, c4 (1 ≤ c1, c2, c3, c4 ≤ 1000) — the costs of the tickets.
                  The second line contains two integers n and m (1 ≤ n, m ≤ 1000) — the number of rickshaws and cabs Ramu is going to use.
                  The third line contains n integers ai (0 ≤ ai ≤ 1000) — the number of times Ramu is going to use the rickshaw number i.
                  The fourth line contains m integers bi (0 ≤ bi ≤ 1000) — the number of times Ramu is going to use the cab number i.

    Constraints: 1 <= T <= 1000 , where T is no of testcases
                 1 ≤ c1, c2, c3, c4 ≤ 1000
                 1 ≤ n, m ≤ 1000
                 0 ≤ ai , bi ≤ 1000

    Output Format: For each testcase , print a single number - the minimum sum of rupees Ramu will have to spend on the tickets in a new line.

    Sample Input:   2
                    1 3 7 19
                    2 3
                    2 5
                    4 4 4
                    4 3 2 1
                    1 3
                    798
                    1 2 3
    
    Sample Output:  12
                    1       
    Explanation: For the first testcase ,
                 The total cost of rickshaws = min( min(2 * 1, 3) + min(5 * 1, 3), 7) = min(5, 7) = 5
                 The total cost of cabs = min( min(4 * 1, 3) + min(4 * 1, 3) + min(4 * 1, 3) , 7) = min ( 9, 7) = 7
                 Total final cost = min( totalCabCost + totalRickshawCost , c4) = min( 5 + 7, 19) = min ( 12, 19) = 12
                We print 12.
*/

#include<iostream>
using namespace std;

int main() {
	int testcases;
   cout<<"Enter total number of testcase: ";
	cin>>testcases;
	
	while(testcases--){
		int ticket1, ticket2, ticket3, ticket4, totalr, totalc,r_routes[1005],c_routes[1005],step;
      
      cout<<"Enter ticket fares: ";
		cin>>ticket1>>ticket2>>ticket3>>ticket4;
		
      cout<<"Enter number of rickshaws and cabs will be used: ";
      cin>>totalr>>totalc;

		// Storing rickshaws routes
      cout<<"Enter number of times rickshaws will be used: ";
		for(step=0; step<totalr; step++){
			cin>>r_routes[step];
		}
		// Storing cabs routes
      cout<<"Enter number of times cabs will be used: ";
		for(step=0; step<totalc; step++){
			cin>>c_routes[step];
		}

		int r_cost_min=0, c_cost_min=0, min_total_cost;

		// calculating minimum rickshaws fare from ticket1 & ticket2
		for(step=0; step<totalr; step++){
			r_cost_min = r_cost_min + min((ticket1*r_routes[step]), ticket2);
		}
		// calculating minimum cabs fare from ticket1 & ticket2
		for(step=0; step<totalc; step++){
			c_cost_min = c_cost_min + min((ticket1*c_routes[step]), ticket2);
		}
		
		// Finding minimum value after comparison from ticket3
		r_cost_min = min(r_cost_min,ticket3);
		c_cost_min = min(c_cost_min,ticket3);
		
		// finding the minimum value after comparison from ticket4
		min_total_cost = min(r_cost_min+c_cost_min, ticket4);
		cout<<min_total_cost<<endl;
	}

	return 0;
}

/*
   This Question is Quite Interesting to read as there remains lots of confusion while reading it. This is because of the amount of data provided in the question is a lot. 
   Every student found himself stuck in the data provided in the question.

   Let's make it a simple one, for this first i need to make sure you are full aware while reading the solution for which i want to give u an example of what exactly we are going to do in this Question.

   Example : Suppose you are buying Maggie packet and the shopkeeper has 2 types of packets available which are as follows :- 
             1 kg 500 Rs and 0.5 Kg 240 Rs and your need is to buy 1 Kg Maggie 
             so in this case obviouly you will buy 2 Half Kgs packets as it will cost 480 Rs and 1 Kg is of 500 Rs …. 
             I know you all have made this calculation . :-]

   Same we are going to implement in this Question.
   c1 - Ticket cost for 1 ride on rickshaw or cab.
   c2 - Ticket cost for unlimited rides on some rickshaw or cabs.

   Now if you have 2 cabs and if you have only these 2 types of tickets available then obviously just like the above example you will first check the cost of buying Two c1 tickets and cost of 1 c2 Ticket. 
   Among them the minimum cost willl be your answer. Now consider 1 more ticket which says c3 is the cost of ride on all rickshaws or on all cabs. 
   then obviously now you will check the minimum cost of buying individual c1 ticket for each ride or c2 ticket for some rickshaw or on some cabs or c3 ticket for all rickshaws or all cabs.

   Now assume there is 1 more ticket saying unlimited cost for ride on all rickshaws and all cabs. Here your final answer will be the minimum cost of previously calculated cost using c1, c2 and c3 tickets and cost of c4 ticket.
*/