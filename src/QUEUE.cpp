 class QUEUE
   {
      private:
       struct node
           { int key; node *next;
             node(int x){key = x; next = 0;}
            }; 
      typedef node *link;
      link head, tail;
      public:
           QUEUE(int) {head = 0;}
           int empty() const {return head == 0;}
           void put(int x)
               {
                 link t = tail;
                 tail = new node(x);
                 if (head == 0)
                        head = tail;
                 else t-> next = tail;
               }
           int get()
              { int v = head->key; link t = head->next;
                delete head; head = t; return v; }
   };
