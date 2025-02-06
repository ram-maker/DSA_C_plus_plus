/*
Adpater pattern is used when two incomaptible interface has to be integrated,
It doesnt modify the actual behaviour of the object rather just transform the incomaptible object to compatible one,
The adapter pattern generally consists of:
adaptee: 
This is generally a class that need to be adopted; Generally this class involve a legacy system , in which client has least control over.
They involve a third party system, a library 

Target:
This is a interface that client expects, It defines method which makes adaptee compatible with client

AdapterClass:
This is the concrete implementation of Target

Client:
This is the client that leverage adapterclass to perform certain functionalities

*/


