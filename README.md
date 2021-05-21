# Trust-Network-and-Trust-Evaluation-Method
Algorithm to Calculate trust among the nodes of the network and derivation of various properties of trust.
### Trust
Trust is widely accepted as a major component of human social relationships.
In general, trust is a measure of confidence that an entity will behave in an expected manner, despite the lack of ability to monitor or control the environment in which it operates.
Trust is a measure of the mutual trust relationship in the network. Different types or facets of trust with different properties.
- I.	Trust in Psychology.
- II.	Trust in Sociology.
- III.	Trust in Computer Science.
The different facets of trust from the various disciplines-
- I.	Calculative.
- II.	Relational.
- III.	Emotional.
- IV.	Cognitive.
- V.	Institutional.
- VI.	Dispositional.
**Properties**
Trust are -
A.	Dynamic
B.	Propagative
C.	Non-transitive
D.	Composable
 
A social network is described as a social structure made of nodes connected by edges that represent one or more specific types of interdependency. Nodes represent individuals, groups, or organizations, while the connecting edges are relations like values, ideas, friendship, trade, etc.
The Trust evaluation model implements trusted network based on trust of the network entity.
Trust is a measure of the mutual trust relationship in the network . Referring to these attributes of trust, the algorithms used in the dynamic trust Evaluation model include:
1.	Trust weighting algorithm, 
2.	Probability statistics methods
3. Game theory algorithms. 
4. Fuzzy algorithms.
 
### Implementation
Multiplication Strategy for Trust Propagation
In this strategy of trust calculation , we use multiplication of direct trust to calculate the trust along path fro source to destination(i.e,from trustor to trustee).
Let ETi be the effective trust of the path i (effective trust ) where < n1 ,n2,n3,
…> are nodes along the path.
ETi =DT(n1,n2) x DT(n2,n3) x DT(n3,n4) x . . . .
Where DT=Direct Trust between two nodes.
We considered multiplicative strategy as because this strategy of trust propagation is very simple, it has some interesting characteristics. Firstly, if all the direct trust values along the trust path have trust value 1, then propagated trust between the source and destination node is also 1. On the other hand, propagated trust value will be 0 if direct trust value between any two nodes is zero. Secondly propagated trust value will be decreased as the number of nodes along the trust path ( or in other words, the degree of separation between source and destination nodes) increases. Thirdly if the source node poorly trust the next node in the chain, the propagated trust value of the path will be low even if the direct trust values between the next nodes in the path is high
 
### Algorithm
  1.	For each possible path between Source and destination
  2.	Calculate Trust of the path, T as follows
  3.	For edges, ei along the path \
          IF ei is the 1st edge \
        	    THEN \
                  Edge_value=trust_value_of_that_edge \
          ELSE \
              Edge_value=trust_value_of_that_edge * (Decay_Rate) \
              Decay_Rate= Decay_Rate * 1.5 \
        END IF 
  4.	Propagated Trust=Average of effective trust values of all the paths.

### Explaination of the Code
In the above algorithm we have considered certain facts about trust . Like trust may vary from one person to other and it is totally random
Here , at first we have created a network , and considered the trust value in the range[0,1] i.e., 0 if person don’t trust the other person and 1 if person is complelety trusted by the other person.
Trust Network is created by assigning random direct trust value to each of the edges assuming that trust value of a person is random and depends on people to people.
For calculating Trust Value between two nodes(people’s) which are indirectly connected , We have stored all the possible path to reach from source node to destination node using Breadth-First-Search (BFS) and calculated Effective Trust for each and every path.
Considering , that Trust decreases as the distance increases between Trustor and Trustee , we have considered the shortest path .
In the above algorithm , we have considered Trust value to decrease at the constant rate (i.e.,Decay Rate ) after each edges along the path .This property is called Propagative property of Trust.
 
_Example_ :
If Alice trust Bob
And Bob trust Harry , then trust value between Alice and Harry may be zero(0) or slightly less than trsut value between Bob and Harry.
Also , Trust is non-transitive
In the above example , Alice may not trust Harry.
We have also derived that if Alice trust Bob completely then it is not necessary that Bob will completely trust Alice i.e., they can different trust value and its is inherent and personal opinion.
If two people don’t have any connection between them or they are not directly connected then Trust value between them will be zero.


I have considered a small network for evaluating the algorithm.



Here , Fig-a is a directed network and Fig-b is network with assigned Trust value.Directed graph is considered because Direct trust value from node-2 to node-3 is different from Direct Trust from node -3 to node- 2.
 
I have considered above graph for my code as example . I have not assigned weight as it will be randomly generated as Direct Trust value. \
_**Time Complexity**_ : O(nm^2) where n is number of node and m is number of edges. \
__Environment Requirement :__ \
Any C++ ide , I have used Dev C++ ide to execute my code.
