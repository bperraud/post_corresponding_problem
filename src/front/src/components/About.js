import React from 'react'
import Domino from './Domino';

export default function About() {
  return (
    <div id="about">
        <h2>
            Le probleme de correspondance de Post (PCP pour les intimes)
            est un problème imaginé en 1946 par Emile Post.
            Il s’agit d’un problème indécidable dans lequel
            il faut trouver une suite de « dominos » à mettre les uns
            à cotés des autres afin que la partie supérieur des dominos
            forment le même mot que la partie inférieure 
            (tout cela sans les faire tourner).
            </h2>
            <h2>
            Par exemple :
            On a les dominos suivant :
            </h2>
            <div id="game">
            <Domino topText="1" bottomText="111"></Domino>
            <Domino topText="10111" bottomText="10"></Domino>
            <Domino topText="10" bottomText="0"></Domino>
            </div>
            <h2>
            Par exemple :
            On a les dominos suivant :
            </h2>
            <div id="game">
            <Domino topText="10111" bottomText="10"></Domino>
            <Domino topText="1" bottomText="111"></Domino>
            <Domino topText="1" bottomText="111"></Domino>
            <Domino topText="10" bottomText="0"></Domino>
            </div>
            <h2>Indécidabilité :</h2>
            <h2>
            On a vu avec l’exemple ci-dessus que résoudre une instance de PCP est fort complexe,
            même si celui-ci est de petite taille. 
            C’est parce que ce problème est indécidable.
            Cela veut dire qu’on ne peut pas prédire la taille de la solution
            en se basant sur les dominos donnés, en effet certaines instances de
            tailles comparables à celle ci-dessus ont une solution d’une longueur de 76 dominos !
            </h2>
        <div id='game'>
        </div>
    </div>
  )
}
