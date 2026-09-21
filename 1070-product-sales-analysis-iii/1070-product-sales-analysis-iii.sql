# Write your MySQL query statement below
select product_id,year as first_year,quantity,price 
from Sales as a 
where (product_id,year) IN(
    select product_id,MIN(year) 
    from sales as s
    group by product_id
);
