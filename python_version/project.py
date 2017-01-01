#!/usr/bin/env python
"""Digital wallet"""

import sys


def find_shortest_path(graph, start, end, path=[]):
     if (len(path) > 4 ):
        shortest = None
     else:
         path = path + [start]   
         if start == end:
             return path
         if not graph.has_key(start):
             return None
         shortest = None
         for node in graph[start]:
             if node not in path:   
                 newpath = find_shortest_path(graph, node, end, path)
                 if newpath:
                     if not shortest or len(newpath) < len(shortest):
                         shortest = newpath
     return shortest


if __name__ == "__main__":
    f = open(sys.argv[1], 'r')
    f2 = open(sys.argv[2], 'r')
    o1 = open(sys.argv[3], 'w')
    ll = f.readline()
    count = 0
    GRAPH = {}
    while ll!="" and count < 100:
          ll = f.readline()
          riga = ll.split(",") 
          id1 = int(riga[1])
          id2 = int(riga[2])
          if not GRAPH.has_key(id1):
             GRAPH[id1] = [id2]
             count += 1
          else:
             GRAPH[id1].append(id2)

    ll1 = f2.readline()  
    count = 0

    while ll1!="" and count < 100:
          ll1 = f2.readline()
          riga = ll1.split(",") 
          id1 = int(riga[1])
          id2 = int(riga[2])
          cam = find_shortest_path(GRAPH, id1, id2, path=[])
          if cam:
             if (len(cam)-1) < 2:
                o1.write('trusted\n')
             else:
                o1.write('unverified\n')
          else:
             o1.write('unverified\n')   
          count += 1       

    f.close()
    f2.close()
    o1.close()
    
