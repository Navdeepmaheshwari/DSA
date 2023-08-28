# Write your MySQL query statement below
select name as Customers from Customers C
left join Orders O 
on O.customerId=C.id 
where O.customerId is NULL;