# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums 
FROM
(SELECT num, 
LAG(num,1)OVER(ORDER BY id) AS p1,
LAG(num,2)OVER(ORDER BY id) AS p2
FROM Logs) consecutiveNums
WHERE num=p1
AND num=p2;