# ToyDB: A simple NoSQL database manager.

This is intended to be a simple NoSQL DBMS implemented in modern C++. It's meant to be something of a demonstration (to potential employers, etc.) as well as a learning opportunity (to those who are trying to pick up C++). As I'm only a learner of C++ myself, there are certain to be bugs or inefficiencies which can be fixed with time. Here is a list of goals, with those in initials being as of yet unimplemented:

### Why is it called ToyDB?

Well, at first, I meant it wasn't a DBMS to be taken seriously, but just to be treated as something like a toy. It still might not necessarily be something to take seriously (you can be the judge of that), but as I got more ideas, I realized it was also a toy in the sense that you can have fun playing with it.

### Why is it written like *that*?

Ah. So you saw. I have a bad habit of overengineering when I start off with an OO approach, so I tried to curb that impulse as much as possible and follow functional/stateless principles instead. Not that they're fundamentally at odds or anything. 


### Your netcode is bad.

I know. Wanna help?

# Steps to "functional"

- [ ] Get the TCP logic working.
- [ ] Implement query parsing.
- [ ] Get user roles, auth, and environment variables working.
- [ ] Implement basic data structures.
- [ ] Implement basic CRUD operations--thread-safe.
- [ ] Implement JSON parsing.

### Basic

- *Implement different forms of DBMS process management: thread-per-worker, process pool, etc.*
- *Implement basic query parsing.*
- *Implement some form of authorization.*
