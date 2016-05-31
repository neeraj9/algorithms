//
// The ISC License
// Copyright (c) 2016, Neeraj Sharma
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include <iostream>

#include <unordered_map>  // c++11
#include <set>
#include <forward_list> // c++11

class Graph {
public:
  typedef std::unordered_map<int, std::set<int> >::iterator StorageIter;

  Graph(bool isDirected);

  bool AddVertex(int key);
  bool RemoveVertex(int key);
  bool AddEdge(int source, int destination);
  bool RemoveEdge(int source, int destination);

  bool Traverse(int source, int destination, std::forward_list<int>& path,
                std::set<int>& visited);

private:
  std::unordered_map<int, std::set<int> > mStorage;
  bool mIsDirected;
};

Graph::Graph(bool isDirected) : mStorage(), mIsDirected(isDirected) {
}

bool Graph::AddVertex(int key) {
  std::set<int> adj_list;
  std::pair<StorageIter, bool> p =
    mStorage.insert(std::make_pair(key, adj_list));
  return p.second;
}

bool Graph::RemoveVertex(int key) {
  size_t num_removed = mStorage.erase(key);
  if (num_removed > 0) {
    StorageIter iter = mStorage.begin();
    for ( ; iter != mStorage.end(); ++iter) {
      iter->second.erase(key);
    }
  }
  return (num_removed > 0);
}

bool Graph::AddEdge(int source, int destination) {
  StorageIter iter_src = mStorage.find(source);
  StorageIter iter_dst = mStorage.find(destination);

  if ((iter_src == mStorage.end()) || (iter_dst == mStorage.end())) {
    return false;
  }

  std::pair<std::set<int>::iterator, bool> p =
    iter_src->second.insert(destination);
  if (!p.second) {
    return false;
  }
  // only for undirected graph
  if (!mIsDirected) {
    iter_dst->second.insert(source);
  }
  return true;
}

bool Graph::RemoveEdge(int source, int destination) {
  StorageIter iter_src = mStorage.find(source);
  StorageIter iter_dst = mStorage.find(destination);

  if ((iter_src == mStorage.end()) || (iter_dst == mStorage.end())) {
    return false;
  }

  size_t num_removed = iter_src->second.erase(destination);
  if ((num_removed > 0) && (!mIsDirected)) {
    num_removed = iter_dst->second.erase(source);
  }
  return (num_removed > 0);
}

bool Graph::Traverse(int source,
                     int destination,
                     std::forward_list<int>& path,
                     std::set<int>& visited) {
  if (visited.find(source) != visited.end()) {
    return false;
  } else {
    visited.insert(source);
  }
  std::cout << "DEBUG " << source << " -> " << destination << std::endl;
  if (source == destination) {
    return true;
  }

  StorageIter iter_src = mStorage.find(source);
  if (iter_src == mStorage.end()) {
    return false;
  }

  std::set<int>::iterator iter = iter_src->second.begin();
  for (; iter != iter_src->second.end(); ++iter) {
    std::cout << "trying " << source << " -> " << *iter << std::endl;
    if (Traverse(*iter, destination, path, visited)) {
      path.push_front(*iter);
      std::cout << "DEBUG DONE" << std::endl;
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  bool directed = true;
  Graph g(directed);

  for (int i = 0; i < 4; ++i) {
    g.AddVertex(i);
  }

	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

  std::forward_list<int> path;
  std::set<int> visited;
  bool found = g.Traverse(1, 3, path, visited);
  if (found) {
    std::forward_list<int>::iterator iter = path.begin();
    for ( ; iter != path.end(); ++iter) {
      std::cout << *iter << ", ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "no valid path found" << std::endl;
  }

  return 0;
}
