//to compile g++ -std=c++11 -o project project.cpp

#include <iostream>
#include <cstdio>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include <vector>
#include "QUEUE.cpp"

using namespace std;




 class GRAPH{
      int numbV;
      struct node
         { int v; node* next;
           node(int x, node* t) {v = x; next = t;}
          };

      typedef node* link;
      vector<link> adj;

      public:
        GRAPH(int V) : adj(V), numbV(V)
          { adj.assign(V,0); }
        void insert(int id1, int id2){
            adj[id1] = new node(id2,adj[id1]);
            adj[id2] = new node(id1,adj[id2]);
               }



// modified breadth first search
        int BFS(QUEUE *q, int key, int check){
                int k;
                int id = 0;
                int output = -1;
                link t;
                vector<int> valori; valori.assign(numbV,-2);
                vector<int> degree; degree.assign(numbV,0);
                q->put(key);
                while ( !q->empty() )
                    {
                      k = q->get(); valori[k] = ++id;
                        if (k == check)
                            {
                              output = degree[k];
                                while ( !q->empty() )
                                q->get();
                                return output;
                            }
  
                      if ( degree[k] < 4){
                      for (t = adj[k]; t != 0; t = t->next)
                         if (valori[t->v] == -2)
                              {
                                 degree[t->v] = degree[k] + 1;
                                 q->put(t->v);
                                 valori[t->v] = -1;
                              }
                                         }
                    }
                 valori.clear();
                 degree.clear();
        return output;
        }
   
      void print_adj_list(int key){
                link iterator;
                for ( iterator = adj[key]; iterator != 0; iterator = iterator->next)
                  {
                     cout  << iterator->v << endl;
                  }
       }

        ~GRAPH(){ }
  };



//Main Function
 int main(int argc, char* argv[])
  {
     string nome_file = argv[1];
     string file_to_be_processed = argv[2];
     string first_o = argv[3];
     string second_o = argv[4];
     string third_o = argv[5];
     int count = 1;  //
     string entrata;
     int id1 = 0;
     int id2 = 0;
     int size = 80000;

     GRAPH grafo(size);
   
     int num_t_to_v = 0;
     cout << "Please, digit the number of operations you want to check" << endl;
     cin >> num_t_to_v;
     num_t_to_v++; num_t_to_v *= 5;
     cout << "Work in progress ... ... ... " << endl;

     ofstream output1;
     ofstream output2;
     ofstream output3;


     ifstream mystream;
     mystream.open(nome_file);
     while ( mystream.good()  ){
                  getline(mystream, entrata, ','); 
                     if (count % 5 == 2 && count > 5){ 
                        id1 = std::stoi(entrata);
                        if (id1 > size) cout << "WARNING: resize the graph, it is too small, increase the variable \" size \" " << endl;
                          }

                     if (count % 5 == 3 && count > 5){
                        id2 = std::stoi(entrata);
                        if (id1 > size) cout << "WARNING: resize the graph, it is too small, increase the variable \" size \" " << endl;
                        }
                  count++;
                      if (count % 5 == 0 ){
                         getline(mystream, entrata, '\n');  
                         count++;
                         if (count > 6)
                         grafo.insert(id1,id2);
                        }

    }
     mystream.close();

     QUEUE queue(0);
     count = 1;
     int risultatover = 0;
     mystream.open(file_to_be_processed);
    

     output1.open(first_o); 
     output2.open(second_o); 
     output3.open(third_o);
     
     while ( mystream.good()  && count < num_t_to_v){
                  getline(mystream, entrata, ','); 
                     if (count % 5 == 2 && count > 5){ 
                        id1 = std::stoi(entrata);
                          }

                     if (count % 5 == 3 && count > 5){
                        id2 = std::stoi(entrata);
                        }
 
                      count++;
                      if (count % 5 == 0 ){
                         getline(mystream, entrata, '\n');  
                         count++;
                               if (count > 6)
                                 {
                                    risultatover =  grafo.BFS(&queue,id1,id2);
                                    switch (risultatover){
                                         case -1:  
                                         output1 << "unverified" << endl;  output2 << "unverified" << endl;  output3 << "unverified" << endl;
                                         break;
                                         case 1:
                                         output1 << "trusted" << endl; output2 << "trusted" << endl; output3 << "trusted" << endl;
                                         break;  
                                         case 2:
                                         output1 << "unverified" << endl; output2 << "trusted" << endl; output3 << "trusted" << endl;
                                         break; 
                                         case 3:
                                         output1 << "unverified" << endl; output2 << "unverified" << endl; output3 << "trusted" << endl;
                                         break; 
                                         case 4:
                                         output1 << "unverified" << endl; output2 << "unverified" << endl; output3 << "trusted" << endl;
                                         break; 
                                      }
                                 }
                        }

    }
   mystream.close();
   output1.close(); output2.close(); output3.close();

}//END MAIN
