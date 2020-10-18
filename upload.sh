#!/bin/bash

ieliek="$(date '+%d-%m-%Y')"

git config --global user.email andris.stuks@gmail.com
git add .
git commit -m "$ieliek"
git push origin master



