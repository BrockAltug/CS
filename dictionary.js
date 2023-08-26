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
    'zebra', 'zebu', 'zorilla',
    'albatross', 'armadillo', 'antelope',
    'bluebird', 'buffalo', 'butterfly',
    'chameleon', 'cheetah', 'crocodile',
    'dalmatian', 'dandelion', 'dolphin',
    'elephant', 'emu', 'eagle',
    'flamingo', 'fennec fox', 'firefly',
    'giraffe', 'gorilla', 'gecko',
    'hedgehog', 'hippopotamus', 'hummingbird',
    'iguana', 'impala', 'insect',
    'jaguar', 'jellyfish', 'jackal',
    'kangaroo', 'kiwi', 'kingfisher',
    'lemur', 'lion', 'llama',
    'meerkat', 'moose', 'macaw',
    'newt', 'nightingale', 'narwhal',
    'ocelot', 'octopus', 'otter',
    'panda', 'panther', 'peacock',
    'quetzal', 'quokka', 'quail',
    'rhinoceros', 'rabbit', 'raccoon',
    'seahorse', 'seagull', 'sloth',
    'tiger', 'toucan', 'tarsier',
    'umbrellabird', 'urchin', 'unicorn',
    'vulture', 'vicuña', 'viper',
    'whale', 'wombat', 'warthog',
    'xenops', 'x-ray tetra', 'xylophone',
    'yak', 'yellowjacket', 'yabby',
    'zebra', 'zebu', 'zorilla'
];

const input = document.querySelector('input');
const ul = document.querySelector('ul');

input.addEventListener('keyup', function(event) {
    const inputValue = input.value.toLowerCase(); // Convert input to lowercase
    let html = '';

    if (inputValue) {
        for (word of WORDS) {
            if (word.toLowerCase().startsWith(inputValue)) { // Convert word to lowercase for comparison
                html += `<li>${word}</li>`;
            }
        }
    }

    ul.innerHTML = html;
});

