import sys
import re

data = sys.stdin.readlines()

# wordsInTheText = data[0].split(' ')

wordsInTheText = re.findall(r"[\w']+", data[0])

lengthOfData = len(wordsInTheText)

# commonly occuring words in Wikipedia articles
placeMetadata = ['at','from','where','here','place','near','to','North','Northern','South',
'Southern','West','Western','East','Eastern','nearby','village','city','country','coastal',
'humid','hot','summer','winter','autumn','kms','via','the','The','world','cold','harsh',
'desert','mountains','valley','tropical']

personMetadata = ['named','age','his','her','was','is','of','did','old','he','she','they','lived',
'we','father','mother','son','daughter','intelligent','smart','had','has','have','been','led',
'worked','born','lived','earned','by','occupation','died','years','ago']

vicinityCheckThreshold = 5

processedData = {}

for wIndex, word in enumerate(wordsInTheText):
	
	# find words that are capitalized i.e. could be proper nouns
	for index,char in enumerate(word):
		
		if char.isupper():
			
			word = word.strip(',')
			word = word.strip('"')
			
			wType = ""

			# define classification rule/s to ascertain the kind of word

			# search for most likely words in the vicinity of the word
			# processing usage clues | common context of the usage words
			# in the English language
			indexToStart = wIndex - vicinityCheckThreshold
			if indexToStart < 0:
				indexToStart = 0  # check for bounds
				
			indexToEnd = wIndex + vicinityCheckThreshold
			if indexToEnd > lengthOfData:
				indexToEnd = lengthOfData # check for bounds

			itr = indexToStart

			while itr < indexToEnd:
				
				wordBeingChecked = wordsInTheText[itr]
				wordBeingChecked = wordBeingChecked.strip(',')
				
				for keyword in personMetadata:
					if keyword == wordBeingChecked:
						wType = 'person'
						break;

				for keyword in placeMetadata:
					if keyword == wordBeingChecked:
						wType = 'place'
						break;		

				itr = itr+1

			if wType == 'place' or wType == 'person':
				processedData[word] = wType
			else:
				processedData[word] = 'place'


# traverse through the dictionary formed and try & understand the
# context of the complete article and make an intelligent guess
# of the unknown
unknown = ''
placeCount = 0;
personCount = 0;
for key in processedData:
	if processedData[key] == 'place':
		placeCount = placeCount + 1;
	else:
		personCount = personCount + 1;

if personCount > placeCount:
	unknown = 'person'
else:
	unknown = 'place'

queries = int(data[1]) + 2
query = 2;
while query < queries:
	queryWord = data[query].strip('\n')
	if queryWord in processedData.keys():
		print processedData[queryWord]
	else:
		print unknown
	query = query + 1			