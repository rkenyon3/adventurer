pipeline {
  agent{
    dockerfile {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }

  stages {
    stage('SCM') {
      steps{
        checkout(
          [
            $class: 'GitSCM',
            branches: scm.branches,
            userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }

    stage('Build') {
      steps {
        sh "
          ls
          mkdir build
          cd build
          ls; pwd; ls ..
          cmake ../src
          cmake --build .
        "
      }
    }    
  }
}
