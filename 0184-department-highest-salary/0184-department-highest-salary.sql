# Write your MySQL query statement below
SELECT d.name as Department ,e.name as Employee, e.salary
FROM Department d 
JOIN Employee e 
ON e.departmentId=d.id 
WHERE(departmentId, salary) IN
(SELECT departmentId,MAX(salary) 
 FROM Employee 
 GROUP BY departmentId);