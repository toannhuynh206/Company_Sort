This was a challenge given to me by a TA in my 104 class to create a project matching system.

Given a list of projects and members you will assign members depending on their role and rankings


This is a sample input read in from STDin
<# of Teams> <# of Members>
<Project 1 Name> <Max # of developers> <Max # of designers>
...
<Project N Name> <Max # of developers> <Max # of designers>
<Member1> <Role> <Project Rankings>
<Member2> <Role> <Project Rankings>
....
<MemberM> <Role> <Project Rankings>

This is a sample ouput format
<Project 1 Name>
TL: <TL Name>
PM: <PM Name>
Designers: <List of Designers>
Developers: <List of Developers>


An example of a correct working project given an valid input is 
INPUT:
3,10
ImagineLA,1,1
Affordable South LA,1,1
Humans Against Trafficking,1,0
Anthony,TL,1,2,3
Bryan,PM,1,2,3
Shirley,Developer,1,2,3
Chloe,TL,2,3,1
Adam,PM,2,3,1
Fayez,Developer,2,3,1
Angela,Designer,2,3,1
Yash,TL,2,3,1
Ava,PM,2,3,1
Brenna,Developer,2,3,1

OUTPUT:
ImagineLA
TL: Anthony
PM: Bryan
Developers: Shirley
Designers: None

Affordable South LA
TL: Chloe
PM: Adam
Developers: Fayez
Designers: Angela

Humans Against Trafficking
TL: Yash
PM: Ava
Developers: Brenna
Designers: None