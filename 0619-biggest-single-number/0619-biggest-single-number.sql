# Write your MySQL query statement below
Select(Select num from MyNumbers group by num having count(num)=1 order by num Desc limit 1) as num ;