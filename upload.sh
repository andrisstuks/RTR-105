#!/bin/bash

ieliek="$(date '+%d-%m-%Y')"

git config --global user.name andrisstuks
git add .
git commit -m "$ieliek"
git push origin master



