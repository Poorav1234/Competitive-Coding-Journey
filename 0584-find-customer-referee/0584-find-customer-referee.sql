# Write your MySQL query statement below
select name from Customer where IFNULL(referee_id, 0) <> 2

-- IFNULL() checks if any value is null then it will simply convert them into given value
-- here we are converting null values into 0 and checking id is not equal to 2 