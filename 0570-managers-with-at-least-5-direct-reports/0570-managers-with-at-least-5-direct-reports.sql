# Write your MySQL query statement below
Select name from employee e1 join (select managerId,Count(*) from employee group by managerId having count(managerId)>=5) e2 ON e1.id=e2.managerId ;