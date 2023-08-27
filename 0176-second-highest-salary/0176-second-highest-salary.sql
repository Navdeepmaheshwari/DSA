# Write your MySQL query statement below

# Return "YES" if the condition is TRUE, or "NO" if the condition is FALSE:
# SELECT IF(500<1000, "YES", "NO");--YES

select if(count(salary)>1,(select distinct salary from Employee 
order by salary desc
LIMIT 1,1),null) as SecondHighestSalary from Employee; 