# ToyDB: A simple NoSQL database

This is intended to be a simple NoSQL database implemented in modern C++. It's meant to be something of a demonstration (to potential employers, etc.) as well as a learning opportunity (to those who are trying to pick up C++). As I'm only a learner of C++ myself, there are certain to be bugs or inefficiencies which can be fixed with time. Here is a list of goals, with those in initials being as of yet unimplemented:

### Basic

- *Implement repos ("toyboxes") and records ("toys")*
  - These will only be strings stored in plaintext files at first, but that will be changed over time.
- *Implement basic CRUD operations in a thread-safe way.*
- *Implement different forms of DBMS process management: thread-per-worker, process pool, etc.*
- *Implement basic query parsing.*
