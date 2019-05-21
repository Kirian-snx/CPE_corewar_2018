.name "zork"
.comment "just a basic living program"

l2:
stir 1,%:live,%1
and r1,%0,r 1
live: live%1
zjmp %:live