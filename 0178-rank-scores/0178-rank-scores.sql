# Write your MySQL query statement below
with t_scores as (
    select score, DENSE_RANK() OVER (order by score desc) as 'rank' from Scores
) select * from t_scores;