var data = require("./p054_poker.js");
var order = "23456789TJQKA"

var scoreCard = function(card) {
	return order.indexOf(card[0]) + 2;
}

var getSuit = function(card) {
	return card[1];
}

var hasCard = function(hand, card) {
	return hand.includes(card);
}

var getLowestCard = function(hand) {
	var lowestScore = 20;
	var lowestCard;
	var score;
	for (var i=0; i<hand.length; i++) {
		score = scoreCard(hand[i]);
		if (score < lowestScore) {
			lowestScore = score;
			lowestCard = hand[i];
		}
	}
	return lowestCard;
}

var getHighestCard = function(hand) {
	var highestScore = 0;
	var highestCard;
	var score;
	for (var i=0; i<hand.length; i++) {
		score = scoreCard(hand[i]);
		if (score > highestScore) {
			highestScore = score;
			highestCard = hand[i];
		}
	}
	return highestCard;
}

var getNextFace = function(card) {
	var i = order.indexOf(card[0]) + 1;
	if (i >= order.length)
		return -1;
	return order[i];
}

var countFaces = function (hand, card) {
	var count = 0;
	for (var i=0; i<hand.length; i++) {
		if (hand[i][0] == card[0])
			count++;
	}
	return count;
}

var isRoyalFlush = function(hand) {
	var suit = getSuit(hand[0]);
	return hasCard(hand, "A" + suit) &&
		hasCard(hand, "K" + suit) &&
		hasCard(hand, "Q" + suit) &&
		hasCard(hand, "J" + suit) &&
		hasCard(hand, "T" + suit);
}

var isFlush = function(hand) {
	var suit = getSuit(hand[0]);
	for (var i=1; i<hand.length; i++) {
		if (getSuit(hand[i]) != suit) {
			return false;
		}
	}
	return true;
}

var getFourOfAKindScore = function(hand) {
	if (countFaces(hand, hand[0]) ==4)
		return scoreCard(hand[0][0]);
	if (countFaces(hand, hand[1]) == 4)
		return scoreCard(hand[1][0]);
	return 0;
}

var isStraightFlush = function(hand) {
	var lowestCard = getLowestCard(hand);
	var suit = getSuit(lowestCard);
	//see if all card in order are in the hand
	var face2 = getNextFace(lowestCard) + suit;
	var face3 = getNextFace(face2) + suit;
	var face4 = getNextFace(face3) + suit;
	var face5 = getNextFace(face4) + suit;
	return hasCard(hand, face2) &&
		hasCard(hand, face3) &&
		hasCard(hand, face4) &&
		hasCard(hand, face5);
}

var isStraight = function(hand) {
	var lowestCard = getLowestCard(hand)[0];
	var face2 = getNextFace(lowestCard);
	var face3 = getNextFace(face2);
	var face4 = getNextFace(face3);
	var face5 = getNextFace(face4);
	var faces = [lowestCard, face2, face3, face4, face5];
	var doneFaces = [];
	for(let i=0;i<hand.length;i++) {
		let face = hand[i][0];
		if (!faces.includes(face) || doneFaces.includes(face)) {
			return false;
		}
		doneFaces.push(face);
	}
	return true;
}

var getThreeOfAKindScore = function(hand) {
	if (countFaces(hand, hand[0]) == 3)
		return scoreCard(hand[0]);
	if (countFaces(hand, hand[1]) == 3)
		return scoreCard(hand[1]);
	if (countFaces(hand, hand[2]) == 3)
		return scoreCard(hand[2]);
	return 0;	
}

var getPairsScores = function(hand) {
	var faces = [];

	for(let i=0;i<hand.length;i++) {
		if ((countFaces(hand, hand[i]) == 2) && !faces.includes(scoreCard(hand[i])))
			faces.push(scoreCard(hand[i]));
	}
	return faces;
}

var scoreHand = function(hand) {
	//score the individual cards
	var score;
	if (isRoyalFlush(hand))
		return 50000;
	if (isStraightFlush(hand))
		return 45000;
	score = getFourOfAKindScore(hand);
	if (score > 0)
		return 40000 + score;
	
	//pairs
	var pairs = getPairsScores(hand);
	
	//full house
	score = getThreeOfAKindScore(hand);
	if (score > 0) {
		//see if there is a pair also
		if ((pairs.length > 0) && (pairs[0] != score)) {
			//full house
			return 35000 + score;
		}
	}
	
	//flush
	if (isFlush(hand))
		return 30000 + scoreCard(getHighestCard(hand));
	if (isStraight(hand))
		return 25000 + scoreCard(getHighestCard(hand));

	//three of a kind
	if (score > 0) {
		return 10000 + score;
	}

	//two pair
	if (pairs.length == 2) {
		if (pairs[0] > pairs[1])
			return 5000 + (10 * pairs[0]) + scoreCard(getHighestCard(hand));
		return 5000 + (10 * pairs[1]) + scoreCard(getHighestCard(hand));
	}
	//one pair
	if (pairs.length == 1) {
		return 1000 + (10 * pairs[0]) + scoreCard(getHighestCard(hand));
	}

	//highest card
	return scoreCard(getHighestCard(hand));
}

console.log("Royal flush:", scoreHand(["TC", "JC", "QC", "KC", "AC"]));
console.log("Straight flush:", scoreHand(["9C", "TC", "JC", "QC", "KC"]));
console.log("Four of a kind:", scoreHand(["3C", "3S", "3H", "QC", "3D"]));
console.log("Four of a kind:", scoreHand(["3C", "4S", "4H", "4D", "4C"]));
console.log("Full house:", scoreHand(["3C", "3S", "JH", "JD", "JC"]));
console.log("Flush:", scoreHand(["2C", "TC", "4C", "QC", "KC"]));
console.log("Straight:", scoreHand(["9C", "TC", "8D", "JD", "QH"]));
console.log("Three of a kind:", scoreHand(["3C", "4S", "4H", "4D", "9C"]));
console.log("Two pair:", scoreHand(["3C", "3S", "4H", "5D", "5C"]));
console.log("Pair:", scoreHand(["3C", "3S", "4H", "5D", "6C"]));
console.log("Nothing:", scoreHand(["3C", "4S", "8H", "TD", "QC"]));

var i = 0;
var sum = 0;
while (i < data.length) {
	let hand1 = data[i].slice(0,5);
	let hand2 = data[i].slice(5,10);
	let score1 = scoreHand(hand1);
	let score2 = scoreHand(hand2);
	
	//console.log(hand1, scoreHand(hand1), hand2, scoreHand(hand2));
	if (score1 == score2) {
		console.log("Same", hand1, hand2, score1);
	}
	if (score1 > score2) {
		sum++;
	}
	i++;
}

console.log("Player 1 won ", sum, " times");
