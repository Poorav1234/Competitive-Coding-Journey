# Write your MySQL query statement below

# DATEDIFF is used to get difference between days

-- select w1.id 
-- from Weather w1
-- inner join Weather w2
-- on DATEDIFF(w1.recordDate,w2.recordDate) = 1
-- WHERE w1.temperature > w2.temperature;

# SUBDATE is used to substract days from that date

select w1.id 
from Weather w1
inner join Weather w2
on SUBDATE(w1.recordDate,1) = w2.recordDate
WHERE w1.temperature > w2.temperature;