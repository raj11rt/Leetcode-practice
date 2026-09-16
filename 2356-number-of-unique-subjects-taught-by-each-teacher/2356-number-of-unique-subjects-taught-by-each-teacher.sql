# Write your MySQL query statement below
SELECT Distinct teacher_id,count(Distinct subject_id) as cnt 
FROM Teacher 
Group by teacher_id;