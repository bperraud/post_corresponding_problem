import {getSession} from '@mysql/xdevapi';
import Pair from './Pair.js';

export default class Instance {
    constructor(size, width, pairs) {
    this.size = size;
    this.width = width;
    this.pairs = pairs; // liste des blocs (ordre pas important + pas de duplication)
    }

    getSize(){
        return this.size;
    }

    getPairs(){
        return this.pairs;
    }

    // 1 si l'instance possède une solution, 0 sinon, -1 si on ne sait pas
    isSolvable(){
        
    }

    async get_from_db() {
        const config = {
            password: 'AXaHUKc])n2D%t*\"T6Ve',
            user: 'PCPadmin',
            host: 'localhost',
            schema: 'PCP'
        };


        await getSession(config)
            .then(session => {
                return session.sql('select * from instances order by rand()')
                    .execute().then(session.close());
            })
            .then(result => {
                let pairs = result.fetchOne()[1];

                this.pairs = [];
                pairs = pairs.split(",");

                for (let i = 0; i < pairs.length / 2; i++) {
                    this.pairs.push(new Pair(pairs[2 * i], pairs[2 * i + 1]))

                }
            }).catch(error => {
                // Use `error` here without `throw`ing -- report it, put it in a log, etc.
                console.log(error)
            });
    }

    displayPairs(){
        for(let i=0; i<this.size; i++){
            process.stdout.write(`| ${this.pairs[i].getTop() + this.pairs[i].getTopPad()} |`)
        }

        console.log()
        for(let i=0; i<this.size; i++){
            process.stdout.write(`| ${this.pairs[i].getBottom() + this.pairs[i].getBottomPad()} |`)
        }
        console.log()
    }
}
