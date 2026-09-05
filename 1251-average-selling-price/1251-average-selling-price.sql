# Write your MySQL query statement below
SELECT p.product_id ,IFNULL(ROUND(SUM(price*units)/SUM(units),2),0) as average_price 
FROM Prices p LEFT JOIN
UnitsSold u ON
p.product_id=u.product_id
AND purchase_date BETWEEN start_date and end_date
GROUP by product_id;