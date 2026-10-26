# Write your MySQL query statement below
select user_id, count(*) as prompt_count, ROUND(AVG(tokens), 2) as avg_tokens
from prompts
group by user_id 
having count(*) >= 3 and avg(tokens) < max(tokens)
order by avg(tokens) desc;