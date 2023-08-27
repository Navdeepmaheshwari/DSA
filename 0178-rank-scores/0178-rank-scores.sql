# Write your MySQL query statement below
select score,
(select count(distinct score) from Scores where score>=s.score) as "rank" 
from Scores s
order by score desc
;