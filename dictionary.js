//a dictionary example to use for dictionary.html
const WORDS = [
    'apple', 'ant', 'avocado',
    'banana', 'bear', 'bird',
    'cat', 'cow', 'camel',
    'dog', 'dolphin', 'duck',
    'elephant', 'eagle', 'emu',
    'fish', 'fox', 'frog',
    'grape', 'goat', 'giraffe',
    'horse', 'hippo', 'hummingbird',
    'iguana', 'insect', 'ibis',
    'jellyfish', 'jaguar', 'jackal',
    'kangaroo', 'koala', 'kookaburra',
    'lion', 'leopard', 'lizard',
    'monkey', 'moose', 'meerkat',
    'newt', 'nightingale', 'nuthatch',
    'ostrich', 'otter', 'octopus',
    'penguin', 'panda', 'parrot',
    'quail', 'quokka', 'quoll',
    'rhinoceros', 'rabbit', 'raven',
    'snake', 'squirrel', 'seagull',
    'tiger', 'toucan', 'turtle',
    'umbrellabird', 'unicorn', 'urial',
    'vulture', 'viper', 'vicuña',
    'walrus', 'whale', 'warthog',
    'xenarthra', 'x-ray tetra', 'xylophone',
    'yak', 'yellowjacket', 'yabby',
    'zebra', 'zebu', 'zorilla'
];

const input = document.querySelector('input');
const ul = document.querySelector('ul');

input.addEventListener('keyup', function(event) {
    const inputValue = input.value.toLowerCase(); // Convert input to lowercase
    let html = '';
    const uniqueMatches = new Set(); // To store unique matches

    if (inputValue) {
        for (word of WORDS) {
            if (word.toLowerCase().startsWith(inputValue)) {
                uniqueMatches.add(word.toLowerCase()); // Add lowercase match to the set
            }
        }
        // Convert unique matches set back to an array for sorting and displaying
        const sortedMatches = [...uniqueMatches].sort();
        sortedMatches.forEach(match => {
            html += `<li>${match}</li>`;
        });
    }

    ul.innerHTML = html;
});


