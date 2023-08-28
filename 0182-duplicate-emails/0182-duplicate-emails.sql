# Write your MySQL query statement below

select email from Person p 
group by email 
having count(email)>1;