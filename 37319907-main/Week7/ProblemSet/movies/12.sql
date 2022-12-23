--Find jhonny depp and helena ... id
-- relate with person_id
--relate with movie_id of their and group by movie_id having vount > 1 ie all non distinct movie_id to both values
--select title from movies of those id
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Johnny Depp" OR name = "Helena Bonham Carter") GROUP BY movie_id HAVING COUNT(*) > 1);