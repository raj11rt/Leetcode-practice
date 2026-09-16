# Write your MySQL query statement below
Select activity_date as day, count(distinct user_id) as active_users 
from Activity
where (activity_date>"2019-06-27" AND activity_date<="2019-07-27") 
Group by activity_date;