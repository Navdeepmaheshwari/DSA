# Write your MySQL query statement below
SELECT e.name as Employee
FROM employee e 
INNER JOIN employee m
ON m.id = e.managerID
WHERE m.salary<e.salary;