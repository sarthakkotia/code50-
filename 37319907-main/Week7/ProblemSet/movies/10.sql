-- ratings>= 9.0
--movie id of these movies
-- directors related to that movieid
--personid of those directors
--print name of people through person_id
SELECT name FROM people WHERE id IN (SELECT person_id FROM directors WHERE movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0));