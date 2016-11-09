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
      struct nodetree
         { int key; int degree; nodetree *l; nodetree *r; 
           nodetree(int x, int d) {key = x; degree = d; l = 0, r = 0;}
         };

      typedef node* link;
      typedef nodetree* linktree;
      vector<link> adj;
      vector<linktree> forest;

      public:
        GRAPH(int V) : adj(V), forest(V), numbV(V)
          { adj.assign(V,0); forest.assign(V,0); }
        void insert(int id1, int id2){
            adj[id1] = new node(id2,adj[id1]);
            adj[id2] = new node(id1,adj[id2]);
               }

  // routines for the forest
       int searchR(linktree h, int id){
         if (h == 0) return -1;
         int t = h->key;
         if (t == id) return h->degree;
         if  (id < t) return searchR(h->l,id);
                   else return searchR(h->r,id);
       }

       void insertR(linktree& h, int id, int d)
          {
           if (h == 0) {h = new nodetree(id,d); return;}
           if (id < h->key )
               insertR(h->l,id,d);
           else
               insertR(h->r,id,d);
          }

// breadth first search
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
                        
                      if ( k != key)
                      insertR(forest[key], k, degree[k]); 
  
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
     cout << "nome_file " << nome_file << endl;
     int count = 1;  //
     string entrata;
     int id1 = 0;
     int id2 = 0;

     GRAPH grafo(78000);
   
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
                          }

                     if (count % 5 == 3 && count > 5){
                        id2 = std::stoi(entrata);
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
     
    bool already_processed[80000];
      for (int i = 0; i < 80000; i++) already_processed[i] = false; 
 
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
                                   if ( already_processed[id1] )
                                     risultatover = grafo.searchR(grafo.forest[id1], id2)
                                   else
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
